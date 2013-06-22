<?php
// Create a new table with the formated movie data.

//
// generic class to all database operations
//

class db {

  private $config     = null;    // database configurations
  private $connection = null;    // Database connection object

  //
  //constructor
  //
  public function __construct($configfile = "../conf/db.ini") {
    // Read from configuration file
    $this->config     = parse_ini_file($configfile);

    // Open a database connection
    $this->connection = mysql_connect($this->config['dbhost'],
                                      $this->config['dbuser'],
                                      $this->config['dbpasswd']);

    // Select database
    mysql_select_db($this->config['dbname'], $this->connection);
  }

  //
  // Execute database queries
  // parameters: Query string
  //
  function execute($query) {
    $result  = mysql_query($query, $this->connection);
    return $result;
  }
}

?>
