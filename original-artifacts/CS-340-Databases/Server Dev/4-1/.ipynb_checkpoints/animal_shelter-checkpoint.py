from pymongo import MongoClient
from pymongo.errors import ConnectionFailure, OperationFailure
from bson.objectid import ObjectId

class AnimalShelter(object):
    """ CRUD operations for Animal collection in MongoDB """

    def __init__(self):
        # Connection Variables
        USER = 'aacuser'
        PASS = 'SNHU1234'
        HOST = '127.0.0.1'  # Localhost since MongoDB is on my Mac
        PORT = 27017
        DB = 'AAC'
        COL = 'animals'

        # Initialize Connection
        try:
            self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER, PASS, HOST, PORT))
            self.database = self.client[DB]
            self.collection = self.database[COL]
            # Test the connection
            self.client.server_info()  # Will raise an exception if connection fails
            print("Connected to MongoDB successfully")
        except ConnectionFailure as e:
            print(f"Could not connect to MongoDB: {e}")
            raise

    # Create method to implement the C in CRUD
    def create(self, data):
        """
        Inserts a document into the specified MongoDB database and collection.
        :param data: A dictionary of key/value pairs to insert.
        :return: True if successful, False otherwise.
        """
        if data is not None and isinstance(data, dict):
            try:
                result = self.collection.insert_one(data)
                return True if result.inserted_id else False
            except OperationFailure as e:
                print(f"Error during insert: {e}")
                return False
        else:
            print("Nothing to save, because data parameter is empty or not a dictionary")
            return False

    # Read method to implement the R in CRUD
    def read(self, query):
        """
        Queries for documents from the specified MongoDB database and collection.
        :param query: A dictionary of key/value pairs to use in the find operation.
        :return: A list of matching documents, or an empty list if the query fails.
        """
        if query is not None and isinstance(query, dict):
            try:
                cursor = self.collection.find(query)  # Returns a cursor
                # Convert cursor to list
                result = list(cursor)
                return result
            except OperationFailure as e:
                print(f"Error during query: {e}")
                return []
        else:
            print("Query parameter is empty or not a dictionary")
            return []