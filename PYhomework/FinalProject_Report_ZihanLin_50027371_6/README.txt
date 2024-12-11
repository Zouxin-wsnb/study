# AI Application - Life Expectancy Prediction

## Project Overview
An analysis and prediction project of global life expectancy using machine learning methods.

## Project Structure
```
.
├── ne_110m_admin_0_countries.shp           # World map data
├── ne_110m_admin_0_countries.shp           # World map data
├── ne_110m_admin_0_countries.shp           # World map data
├── world.csv              # Global basic data
├── life.csv              # Life expectancy data
├── FinalProject_Report_ZihanLin_50027371_6.pdf  # Main report part
├── icsReport.ipynb           # Main analysis code
└── README.txt                  # Project documentation
                
```

## Environment Setup
- Python 3.12.4
- Conda environment management

## Project Components

The project consists of three main parts:

### 1. Data Preprocessing
- World map visualization
- Life expectancy data cleaning
- Feature engineering and data standardization

### 2. Model Comparison (Task A)
- K-Nearest Neighbors (K-NN)
- Decision Trees
- Random Forest
- XGBoost
- Ensemble Learning Methods

### 3. Feature Selection Methods (Task B)
- SelectKBest feature selection
- Principal Component Analysis (PCA)
- Raw feature selection

## Installation

```bash
# Create conda environment
conda create -n myenv python=3.12.4
conda activate myenv

# Install dependencies
pip install pandas numpy scikit-learn xgboost geopandas matplotlib seaborn
```

## Usage Instructions

1. Clone the project locally
2. Install required dependencies
3. Ensure all data files are in the correct location
4. Open icsReport.ipynb with Jupyter Notebook
5. Run all cells in sequence

## Results Analysis

The project includes multiple visualization outputs:
- Global life expectancy distribution map
- Model performance comparisons
- Feature importance analysis
- Feature selection method comparisons

## Notes

- Ensure all data files are in the same directory
- Complete dependency installation is required
- Recommended to run in a dedicated conda environment