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

  def runquery(self, query):
    try:
      # Execute the SQL command
      self.cursor.execute(query)
      db.commit()
    except:
      # Rollback in case there is any error
      db.rollback()
