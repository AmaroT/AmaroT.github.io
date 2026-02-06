from pymongo import MongoClient
from bson.objectid import ObjectId
import re

class AnimalShelter:
    """Enhanced CRUD operations for Animal collection in MongoDB"""

    def __init__(self, username, password, role="user"):
        HOST = '127.0.0.1'
        PORT = 27017
        DB = 'AAC'
        COL = 'animals'

        self.role = role

        try:
            self.client = MongoClient('mongodb://%s:%s@%s:%d/?authSource=admin' % (username, password, HOST, PORT))
            self.database = self.client[DB]
            self.collection = self.database[COL]
            print("Connection to MongoDB successful")
        except Exception as e:
            print(f"Connection failed: {e}")
            raise

    def create(self, data):
        if self.role != "admin":
            raise PermissionError("Only admins can create records")
        if not isinstance(data, dict):
            raise ValueError("Data parameter must be a dictionary")
        if data:
            try:
                result = self.collection.insert_one(data)
                return True if result.inserted_id else False
            except Exception as e:
                print(f"Insert failed: {e}")
                return False
        else:
            raise ValueError("Nothing to save, data parameter is empty")

    def read(self, query):
        if not isinstance(query, dict):
            raise ValueError("Query parameter must be a dictionary")
        sanitized_query = {k: re.sub(r'[;$]', '', str(v)) for k, v in query.items()}
        try:
            cursor = self.collection.find(sanitized_query)
            return list(cursor)
        except Exception as e:
            print(f"Query failed: {e}")
            return []

    def update(self, query, update_data):
        if self.role != "admin":
            raise PermissionError("Only admins can update records")
        if not isinstance(query, dict) or not isinstance(update_data, dict):
            raise ValueError("Query and update_data must be dictionaries")
        sanitized_query = {k: re.sub(r'[;$]', '', str(v)) for k, v in query.items()}
        try:
            result = self.collection.update_many(sanitized_query, {"$set": update_data})
            return result.modified_count
        except Exception as e:
            print(f"Update failed: {e}")
            return 0

    def delete(self, query):
        if self.role != "admin":
            raise PermissionError("Only admins can delete records")
        if not isinstance(query, dict):
            raise ValueError("Query parameter must be a dictionary")
        sanitized_query = {k: re.sub(r'[;$]', '', str(v)) for k, v in query.items()}
        try:
            result = self.collection.delete_many(sanitized_query)
            return result.deleted_count
        except Exception as e:
            print(f"Delete failed: {e}")
            return 0

    def get_rescue_stats(self, rescue_type=None):
        pipeline = [
        {"$match": {"animal_type": "Dog"}},
        {"$group": {"_id": "$breed", "count": {"$sum": 1}}},
        {"$sort": {"count": -1}},
        {"$limit": 10}
        ]
        if rescue_type == "Water":
            pipeline[0]["$match"]["breed"] = {"$regex": "Retriever|Newfoundland", "$options": "i"}  # case-insensitive partial match
            pipeline[0]["$match"]["sex_upon_outcome"] = {"$regex": "Intact Female", "$options": "i"}
            pipeline[0]["$match"]["age_upon_outcome_in_weeks"] = {"$gte": 26, "$lte": 156}
        elif rescue_type == "Mountain":
            pipeline[0]["$match"]["breed"] = {"$regex": "Shepherd|Malamute|Sheepdog|Husky|Rottweiler", "$options": "i"}
            pipeline[0]["$match"]["sex_upon_outcome"] = {"$regex": "Intact Male", "$options": "i"}
            pipeline[0]["$match"]["age_upon_outcome_in_weeks"] = {"$gte": 26, "$lte": 156}
        elif rescue_type == "Disaster":
            pipeline[0]["$match"]["breed"] = {"$regex": "Doberman|Shepherd|Retriever|Bloodhound|Rottweiler", "$options": "i"}
            pipeline[0]["$match"]["sex_upon_outcome"] = {"$regex": "Intact Male", "$options": "i"}
            pipeline[0]["$match"]["age_upon_outcome_in_weeks"] = {"$gte": 20, "$lte": 300}
        try:
            results = list(self.collection.aggregate(pipeline))
            return results
        except Exception as e:
            print(f"Aggregation failed: {e}")
            return []