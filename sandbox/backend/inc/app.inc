<?php
//
// Main application class
//

require_once('db.inc');

// Define Operations
define ('OPERATION', 'operation');

class app {

  private $postargs     = null;
  private $getargs      = null;
  private $dbconnection = null;

  //
  // Constructor
  //
  public
  function __construct() {

    parent::__construct();
    $this->postargs = $_POST;
    $this->getargs  = $_GET;

    // Open a database connection
    $this->dbconnection = new db();
  }

  //
  // Main function
  //
  public
  function run() {
    if (isset($this->postargs[OPERATION])) {
      switch ($this->postargs[OPERATION]) {
        case OPERATION1    : $this->operation1(); break;
        default            : $this->default(); break;
      }
    }
    return SUCCESS;
  }
}
?>
