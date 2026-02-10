# Databases

## Original Artifact
**Course**: CS-340 – Advanced Programming Concepts  
**Artifact**: MongoDB-based application (`animal_shelter.py` CRUD class + `ProjectTwoDashboard.ipynb` dashboard)  

**Description**: Python module providing CRUD operations for the AAC animals collection in MongoDB, used in a Dash-based web dashboard to filter rescue types, display paginated tables, breed distribution pie charts, and geolocation maps.

## Enhancement Description
The enhancement adds advanced analytics and security features to make the module more robust and production-ready:

### Key Enhancements
- Complex aggregation pipelines for grouping, sorting, averages, and statistics (e.g., by breed/outcome type)  
- Basic input sanitization (regex to remove dangerous characters like `;` and `$`)  
- Role-based access simulation (simple admin/user checks for create/update/delete)  
- Improved error handling and logging for connection/query failures  
- Updated dashboard to display all loaded data (rescue-type filters skipped for simplicity and reliability)

These improvements address original limitations (basic queries, no analytics depth, minimal security) and showcase skills in advanced NoSQL querying, data summarization, secure practices, and full-stack integration.

### Alignment with Course Outcomes
- **Outcome 2**: Professional visual communications through data visualizations and summarization  
- **Outcome 4**: Innovative use of MongoDB aggregation tools to deliver analytical value  
- **Outcome 5**: Security mindset — anticipating exploits and implementing mitigation via sanitization and role simulation  

### Visuals & Code
**Live Code & Details**  
[View enhanced CS-340 folder and code](https://github.com/AmaroT/AmaroT.github.io/tree/main/enhanced-artifacts/cs-340)  
[README with summary & test instructions](https://github.com/AmaroT/AmaroT.github.io/blob/main/enhanced-artifacts/cs-340/README.md)

This work showcases advanced database querying, secure data handling, and full-stack integration skills.
