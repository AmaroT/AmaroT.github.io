from pymongo import MongoClient
from bson.objectid import ObjectId

class AnimalShelter:
    """CRUD operations for Animal collection in MongoDB"""

    def __init__(self, username, password):
        # Connection variables
        HOST = '127.0.0.1'
        PORT = 27017
        DB = 'AAC'
        COL = 'animals'

        # Initialize connection
        try:
            self.client = MongoClient('mongodb://%s:%s@%s:%d' % (username, password, HOST, PORT), authSource=DB)
            self.database = self.client[DB]
            self.collection = self.database[COL]
            print("Connection to MongoDB successful")
        except Exception as e:
            print(f"Connection failed: {e}")
            raise

    def create(self, data):
        """Insert a document into the specified MongoDB collection."""
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
        """Query documents from the specified MongoDB collection."""
        if not isinstance(query, dict):
            raise ValueError("Query parameter must be a dictionary")
        try:
            cursor = self.collection.find(query)
            return list(cursor)
        except Exception as e:
            print(f"Query failed: {e}")
            return []

    def update(self, query, update_data):
        """Update documents in the specified MongoDB collection."""
        if not isinstance(query, dict) or not isinstance(update_data, dict):
            raise ValueError("Query and update_data parameters must be dictionaries")
        try:
            result = self.collection.update_many(query, {"$set": update_data})
            return result.modified_count
        except Exception as e:
            print(f"Update failed: {e}")
            return 0

    def delete(self, query):
        """Delete documents from the specified MongoDB collection."""
        if not isinstance(query, dict):
            raise ValueError("Query parameter must be a dictionary")
        try:
            result = self.collection.delete_many(query)
            return result.deleted_count
        except Exception as e:
            print(f"Delete failed: {e}")
            return 0
