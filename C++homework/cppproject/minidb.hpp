#ifndef MINIDB_HPP  //好习惯
#define MINIDB_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Database {
public:
    string name;
    unordered_map<string, vector<vector<string>>> tables;

    Database() = default;
    Database(const string& dbName) : name(dbName) {}
};

class MiniDB {
public:

    unordered_map<string, Database> databases;
    Database* currentDatabase = nullptr;

void create_database(const string& dbName)
{
    if (databases.find(dbName) != databases.end()) {
        cerr << "Database " << dbName << " already exists" << endl;
        return;
    }
    databases[dbName] = Database(dbName);
    save_database(databases[dbName]);
}

void use_database(const string& dbName)
{
    load_database(dbName + ".db");
    if (databases.find(dbName) == databases.end()) {
        cerr << "Database " << dbName << " does not exist" << endl;
        return;
    }
    currentDatabase = &databases[dbName];
}

void create_table(const string& tableName, const vector<string>& columns)
{
    if(currentDatabase)
    {
        if (currentDatabase->tables.find(tableName) != currentDatabase->tables.end()) {
            cerr << "Table " << tableName << " already exists" << endl;
            return;
        }
        currentDatabase->tables[tableName] = {columns};
        save_database(*currentDatabase);
    }
    else
    {
        cerr << "No database selected" << endl;
    }
}

void drop_table(const string& tableName)
{
    if(currentDatabase)
    {
        if (currentDatabase->tables.find(tableName) == currentDatabase->tables.end()) {
            cerr << "Table " << tableName << " does not exist" << endl;
            return;
        }
        currentDatabase->tables.erase(tableName);
        save_database(*currentDatabase);
    }
    else
    {
        cerr << "No database selected" << endl;
    
    }
}

void insert_into_table(const string& tableName, const vector<string>& values)
{
    if(currentDatabase)
    {
        if(currentDatabase->tables.find(tableName)!=currentDatabase->tables.end())
        {
            if(values.size()!=currentDatabase->tables[tableName][0].size())
            {
                cerr<<"Number of values does not match number of columns"<<endl;
                return;
            }
            currentDatabase->tables[tableName].push_back(values);
            save_database(*currentDatabase);
        }
        else
        {
            cerr<<"Table "<<tableName<<" does not exist"<<endl;
        }
    }
    else
    {
        cerr<<"No database selected"<<endl;
    }
}

void select_to_file(const string& tableName, const vector<string>& columnNames, const vector<string>& conditions, const string& outputFile)
{
    if(currentDatabase)
    {
        if(currentDatabase->tables.find(tableName)!=currentDatabase->tables.end())
        {
            ofstream file(outputFile);
            const auto& table = currentDatabase->tables[tableName];
            const auto& header = table.front();
            for(const auto& columnName:columnNames)
            {
                if(columnName==columnNames.back())
                {
                    file<<columnName<<endl;
                }
                else
                {
                    file<<columnName<<",";
                }
            }
            file<<endl;
            for(size_t i=1;i<table.size();i++)
            {
                bool match=true;
                for(size_t j=0;j<conditions.size();j+=3)
                {
                    auto it = find(header.begin(), header.end(), conditions[j]);
                    if(it!=header.end())
                    {
                        size_t index=distance(header.begin(),it);
                        if(conditions[j+1]=="="&&table[i][index]!=conditions[j+2])
                        {
                            match=false;
                        }
                        else if(conditions[j+1]=="<"&&table[i][index]>=conditions[j+2])
                        {
                            match=false;
                        }
                        else if(conditions[j+1]==">"&&table[i][index]<=conditions[j+2])
                        {
                            match=false;
                        }
                    }
                }
                if(match)
                {
                    for(const auto& columnName:columnNames)
                    {
                        auto it=find(header.begin(),header.end(),columnName);
                        if(it!=header.end())
                        {
                            auto index=distance(header.begin(),it);
                            if(columnName==columnNames.back())
                            {
                                file<<table[i][index]<<endl;
                            }
                            else
                            {
                                file<<table[i][index]<<",";
                            }
                        }
                    }
                }
            }
            file<<"---------------"<<endl;
            file.close();
        }
        else
        {
            cerr<<"Table "<<tableName<<" does not exist"<<endl;
        }
    }
    else
    {
        cerr<<"No database selected"<<endl;
    }
}

void inner_join_file(const string& table1, const string& table2, const vector<string>& columnNames, const vector<string>& conditions, const string& outputFile)
{
    if(currentDatabase)
    {
        if(currentDatabase->tables.find(table1)!=currentDatabase->tables.end()&&currentDatabase->tables.find(table2)!=currentDatabase->tables.end())
        {
            ofstream file(outputFile);
            const auto& res_table=currentDatabase->tables[table1];
            const auto& tag_table=currentDatabase->tables[table2];
            const auto& res_header=res_table.front();
            const auto& tag_header=tag_table.front();
            vector<pair<string,string>> join_columns;
            vector<pair<string,string>> join_conditions;
            //分割‘.’前后的表达式
            auto parse = [](const string& col) {
                size_t dot_pos = col.find('.');
                return make_pair(col.substr(0, dot_pos), col.substr(dot_pos + 1));
            };
            for(const auto& column:columnNames)
            {
                join_columns.push_back(parse(column));
            }
            for(const auto& condition:conditions)
            {
                join_conditions.push_back(parse(condition));
            }
            //打印列名
            for(const auto& column:join_columns)
            {
                if(column==join_columns.back())
                {
                    file<<column.second<<endl;
                }
                else
                {
                    file<<column.second<<",";
                }
            }
            for(size_t i=1;i<res_table.size();i++)
            {
                for(size_t j=1;j<tag_table.size();j++)
                {
                    bool match=true;
                    for(size_t k=0;k<conditions.size();k+=2)
                    {
                        auto it1=find(res_header.begin(),res_header.end(),join_conditions[k].second);
                        auto it2=find(tag_header.begin(),tag_header.end(),join_conditions[k+1].second);
                        if(it1!=res_header.end()&&it2!=tag_header.end())
                        {
                            size_t index1=distance(res_header.begin(),it1);
                            size_t index2=distance(tag_header.begin(),it2);
                            if(res_table[i][index1]!=tag_table[j][index2])
                            {
                                match=false;
                                break;
                            }
                        }
                    }
                    if(match)
                    {
                        for(const auto& column:join_columns)
                        {
                            auto it1=find(res_header.begin(),res_header.end(),column.second);
                            auto it2=find(tag_header.begin(),tag_header.end(),column.second);
                            if(it1!=res_header.end())
                            {
                                size_t index1=distance(res_header.begin(),it1);
                                if(column==join_columns.back())
                                {
                                    file<<res_table[i][index1]<<endl;
                                }
                                else
                                {
                                    file<<res_table[i][index1]<<",";
                                }
                            }
                            else if(it2!=tag_header.end())
                            {
                                size_t index2=distance(tag_header.begin(),it2);
                                if(column==join_columns.back())
                                {
                                    file<<tag_table[j][index2]<<endl;
                                }
                                else
                                {
                                    file<<tag_table[j][index2]<<",";
                                }
                            }
                        }
                    }
                }
            }
            file<<"---------------"<<endl;
            file.close();
        }
    }
}

void update_table(const string& tableName, const vector<pair<string, string>>& updates, const vector<string>& conditions)
{
    if(currentDatabase)
    {
        if(currentDatabase->tables.find(tableName)!=currentDatabase->tables.end())
        {
            auto& table=currentDatabase->tables[tableName];
            if(conditions.empty())
            {
                for(size_t i=1;i<table.size();i++)
                {
                    for(const auto& update:updates)
                    {
                        auto it=find(table.front().begin(),table.front().end(),update.first);
                        if(it!=table.front().end())
                        {
                            auto index=distance(table.front().begin(),it);
                            table[i][index]=update.second;
                        }
                    }
                }
            }
            else
            {
                const auto& header=table.front();
                for(size_t i=1;i<table.size();i++)
                {
                    bool match=true;
                    for(size_t j=0;j<conditions.size();j+=3)
                    {
                        auto it = find(header.begin(), header.end(), conditions[j]);
                        if(it!=header.end())
                        {
                            size_t index=distance(header.begin(),it);
                            if(conditions[j+1]=="="&&table[i][index]!=conditions[j+2])
                            {
                                match=false;
                            }
                            else if(conditions[j+1]=="<"&&table[i][index]>=conditions[j+2])
                            {
                                match=false;
                            }
                            else if(conditions[j+1]==">"&&table[i][index]<=conditions[j+2])
                            {
                                match=false;
                            }
                        }
                    }
                    if(match)
                    {
                        for(const auto& update:updates)
                        {
                            auto it=find(table.front().begin(),table.front().end(),update.first);
                            if(it!=table.front().end())
                            {
                                auto index=distance(table.front().begin(),it);
                                table[i][index]=update.second;
                            }
                        }
                    }
                }
            }
            save_database(*currentDatabase);
        }
    }
}

void deleteFromTable(const string& tableName, const vector<string>& conditions)
{
    if(currentDatabase)
    {
        if(currentDatabase->tables.find(tableName)!=currentDatabase->tables.end())
        {
            auto& table=currentDatabase->tables[tableName];
            if(conditions.empty())
            {
                table.erase(table.begin()+1,table.end()); 
            }
            else
            {
                const auto& header=table.front();
                for(size_t i=1;i<table.size();i++)
            {
                bool match=true;
                for(size_t j=0;j<conditions.size();j+=3)
                {
                    auto it = find(header.begin(), header.end(), conditions[j]);
                    if(it!=header.end())
                    {
                        size_t index=distance(header.begin(),it);
                        if(conditions[j+1]=="="&&table[i][index]!=conditions[j+2])
                        {
                            match=false;
                        }
                        else if(conditions[j+1]=="<"&&table[i][index]>=conditions[j+2])
                        {
                            match=false;
                        }
                        else if(conditions[j+1]==">"&&table[i][index]<=conditions[j+2])
                        {
                            match=false;
                        }
                    }
                }
                if(match)
                {
                    table.erase(table.begin()+i);
                    i--;
                }
            }
            }
            save_database(*currentDatabase);
        }
        else
        {
            cerr<<"Table "<<tableName<<" does not exist"<<endl;
        }
    }
    else
    {
        cerr<<"No database selected"<<endl;
    }
}

void save_database(const Database& db)
{
    ofstream file(db.name+".db");
    if(db.tables.empty())
    {
        return;
    }
    for(const auto& table:db.tables)
    {
        file<<"TABLE "<<" "<<table.first<<endl;
        for(const auto& column:table.second)
        {
            for(const auto& column_name:column)
            {
                if(column_name==column.back())
                {
                    file<<column_name<<endl;
                }
                else
                {
                    file<<column_name<<" ";
                }
            }
        }
        file<<"end"<<endl;
    }
}

void load_database(const string& db)
{
    ifstream file(db);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << db << endl;
        return;
    }
    string line,current_table;
    while(getline(file,line))
    {
        if(line.substr(0,5)=="TABLE")
        {
            current_table=line.substr(6);
            currentDatabase->tables[current_table]={};
        }
        else if(line=="end")
        {
            continue;
        }
        else
        {
            istringstream data(line);
            string column;
            vector<string> columns;
            while(data>>column)
            {
                columns.push_back(column);
            }
            currentDatabase->tables[current_table].push_back(columns);
        }
    }
}


};

void executeSQL(const string& filename, const string& outputFile, MiniDB& db);

#endif