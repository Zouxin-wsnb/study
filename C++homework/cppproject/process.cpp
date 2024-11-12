#include "minidb.hpp"

void executeSQL(const string& filename, const string& outputFile, MiniDB& db)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string sqlCommand;
    while (getline(file, line)) {
        sqlCommand += line + " ";
        if (line.back() == ';') {
            sqlCommand.pop_back();
            istringstream iss(sqlCommand);
            string command;
            iss >> command;

        if(command=="CREATE")
        {
            string type;
            iss>>type;
            if(type=="DATABASE")
            {
                string dbName;
                iss>>dbName;
                db.create_database(dbName);
            }
            else if(type=="TABLE")
            {
                string tableName;
                iss>>tableName;
                vector<string> columns;
                string column_name,column_type,extra;
                iss>>extra;
                while(iss>>column_name>>column_type)
                {
                    if(column_type.back()==',')
                    {
                        column_type.pop_back();
                    }
                    columns.push_back(column_name + " " + column_type);
                }
                db.create_table(tableName,columns);
            }
        }
        else if(command=="DROP")
        {
            string extra,name;
            iss>>extra>>name;
            db.drop_table(name);
        }
        else if(command=="USE")
        {
            string extra,name;
            iss>>extra>>name;
            db.use_database(name);
        }
        else if(command=="SELECT")
        {
            vector<string> columns;
            string value,extra;
            size_t innerJoinPos = sqlCommand.find("INNER JOIN");
            if(innerJoinPos!=string::npos)
            {
                string res_table,join_table,res_column,join_column,condition1,condition2;
                string from,inner,join,on,extra;
                iss>>res_column>>join_column>>from>>res_table>>inner>>join>>join_table>>on>>condition1>>extra>>condition2;
                res_column.pop_back();
                vector<string> columns,conditions;
                columns.push_back(res_column);
                columns.push_back(join_column);
                conditions.push_back(condition1);
                conditions.push_back(condition2);
                db.inner_join_file(res_table,join_table,columns,conditions,outputFile);
            }
            else{
            while(iss>>value>>extra)
            {
                if(extra=="FROM")
                {
                    columns.push_back(value);
                    break;
                }
                columns.push_back(value);
            }
            string tablename;
            iss>>tablename;
            std::vector<std::string> conditions;
            size_t wherePos = sqlCommand.find("WHERE");
            if (wherePos != string::npos) {
                std::string conditionStr = sqlCommand.substr(wherePos + 6);
                std::istringstream conditionStream(conditionStr);
                std::string cond;
                while (conditionStream >> cond) {
                    conditions.push_back(cond);
                }
            }
            db.select_to_file(tablename,columns,conditions,outputFile);
            }
        }
        else if(command=="INSERT")
        {
            string extra,tablename,extra2;
            iss>>extra>>tablename>>extra2;
            vector<string> values;
            string data;
            while(iss>>data)
            {
                values.push_back(data);
            }
            db.insert_into_table(tablename,values);
        }
        else if(command=="UPDATE")
        {
            string tableName,set,where;
            iss>>tableName>>set;
            vector<pair<string,string>> updates;
            string column, equal, newValue;
            while(iss>>column>>equal>>newValue)
            {
                if(newValue.back()==',')
                {
                    newValue.pop_back();
                    updates.push_back(make_pair(column,newValue));
                }
                else
                {
                    updates.push_back(make_pair(column,newValue));
                    break;
                }
            }
            vector<string> conditions;
            if(iss>>where)
            {
                string condition;
                while(iss>>condition)
                {
                    conditions.push_back(condition);
                }
            }
            db.update_table(tableName,updates,conditions);
        }
        else if(command=="DELETE")
        {
            string from, tableName, where;
            iss >> from >> tableName;
            vector<std::string> conditions;
            string condition;
            if (iss >> where) {
                while (iss >> condition) {
                    conditions.push_back(condition);
                }
            }
            db.deleteFromTable(tableName, conditions);
        }
        sqlCommand.clear();
        }
    }
    file.close();//记住关闭文件（
}


