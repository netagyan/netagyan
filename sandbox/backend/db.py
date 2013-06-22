#!/usr/bin/python

import MySQLdb

DBHOST = "localhost"
DBUSER = "root"
DBPASS = "general"
DBNAME = "netagyan"

class db:
  def __init__(self):
    self.connection = MySQLdb.connect(DBHOST, DBUSER, DBPASS, DBNAME)
    self.cursor     = self.connection.cursor()

  # insert rows into db
  def insert(self, query):
    try:
      # Execute the SQL command
      self.cursor.execute(query)
      self.connection.commit()
      return true
    except:
      # Rollback in case there is any error
      db.rollback()
      return false

  # select from database
  def select(self, query):
    try:
      # Execute the SQL command
      self.cursor.execute(query)
      # Fetch all the rows in a list of lists and return.
      return self.cursor.fetchall()
    except:
      # Rollback in case there is any error
      db.rollback()
      return false

  # update rows in db
  def update(self, query):
    try:
      # Execute the SQL command
      self.cursor.execute(query)
      self.connection.commit()
      return true
    except:
      # Rollback in case there is any error
      db.rollback()
      return false
