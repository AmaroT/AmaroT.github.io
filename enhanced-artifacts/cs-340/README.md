# CS-499 Milestone Four: Enhanced Databases Artifact

## Original Artifact
- Course: CS-340 Client/Server Development  
- Files: animal_shelter.py (CRUD class), ProjectTwoDashboard.ipynb (Dash dashboard)  
- Purpose: MongoDB CRUD for AAC animals + interactive dashboard for data visualization

## Enhancement Summary
- Added complex aggregation pipelines for breed/outcome statistics  
- Added basic input sanitization (regex to remove dangerous characters)  
- Added role-based access simulation (admin/user) for create/update/delete  
- Updated dashboard to display all loaded data (filters skipped for simplicity)  
- Improved error handling and logging

## Before vs After
- Original: Basic CRUD, simple queries, no aggregations, minimal security  
- Enhanced: Advanced analytics pipelines, input safety, role checks, full dashboard with table, pie chart, map

## Setup & Environment (How to Run Locally)
1. **Prerequisites** (macOS):  
   - Python 3.11+ (install via Homebrew: `brew install python@3.11` if needed)  
   - MongoDB Community Edition (install via Homebrew: `brew tap mongodb/brew && brew install mongodb-community`)  
   - Start MongoDB: `brew services start mongodb/brew/mongodb-community`

2. **Create virtual environment** (in this folder):  
```
python3 -m venv venv
source venv/bin/activate
```
3. **Install dependencies**:
```
   pip install dash dash-leaflet pymongo pandas plotly jupyter
```

5. **Create or use a test CSV** (optional – for data):  
- Place a file named `animal_shelter.csv` in this folder with columns:  
  `animal_type,breed,sex_upon_outcome,age_upon_outcome_in_weeks,location_lat,location_long,name,outcome_type`  
- Or insert test data manually (see below).

5. **Insert test data** (run once in Jupyter or Python):  
```python
from enhanced_animal_shelter import AnimalShelter

db = AnimalShelter("aacuser", "test123", role="admin")

test_data = [
    {"animal_type": "Dog", "breed": "Labrador Retriever Mix", "sex_upon_outcome": "Intact Female", "age_upon_outcome_in_weeks": 50, "location_lat": 30.2672, "location_long": -97.7431, "name": "Buddy", "outcome_type": "Adoption"},
    {"animal_type": "Dog", "breed": "German Shepherd", "sex_upon_outcome": "Intact Male", "age_upon_outcome_in_weeks": 80, "location_lat": 30.45, "location_long": -97.8, "name": "Rex", "outcome_type": "Adoption"}
]

for doc in test_data:
    db.create(doc)
print("Test data inserted")
```

6. **Run the dashboard**:
```bash
jupyter notebook enhanced_dashboard.ipynb
```
- Open in browswer, run all cells
- Dashboard shows table with all loaded data, breed distribution pie chart, map (select row to update marker)





