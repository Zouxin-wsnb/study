
# Use of AI---prediction of Life expectancy


## environment
The icsReport.ipynb is based on conda.
The version of python is 3.12.4.


## instructions
This project is mainly divided into 3 parts: Preprocessing, Task A, Task B

### Preprocessing
Make a preview of life expectancy of different contries(use ne_110m_admin_0_countries.shp); clean the data
### Task A
Compare different models
### Task B
Comparison of different data selection methods


## dependencies
Please make sure to install the following dependencies before running the code:

```bash
conda create -n myenv python=3.12.4
conda activate myenv
pip install pandas numpy scikit-learn xgboost geopandas matplotlib seaborn
