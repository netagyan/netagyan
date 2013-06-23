<?php
//
// Main application class
//

require_once('db.inc');

// Define SUCCESS and FAILURE
define ('SUCCESS', 'success');
define ('FAILURE', 'failure');

// Define Operations
define ('OPERATION'     , 'operation');
define ('GETMPLIST'     , 'getmplist');
define ('GETMPDETAILS'  , 'getmpdetails');
define ('GETALLDETAILS' , 'getalldetails');
define ('GRAPHSEARCH'   , 'graphsearch');
define ('RUNQUERY'      , 'runquery');

class app {

  private $postargs     = null;
  private $getargs      = null;
  private $dbconnection = null;

  //
  // Constructor
  //
  public
  function __construct() {

    $this->postargs = $_POST;
    $this->getargs  = $_GET;

    // Open a database connection
    $this->dbconnection = new db();
  }

  //
  // Return MP list
  //
  private 
  function graphsearch($name) {
    $query           = "select * from query where question like '%" . $name . "%'";
    $result          = $this->dbconnection->execute($query);
    $jsonarray       = array();
    $i               = 0;
    while ( ($values = mysql_fetch_assoc($result)) ) {
      $jsonarray[$i] = array(
        'question'   => $values['question'],
        'query'      => $values['query']
      );
      $i++;
    }
    printf("%s", json_encode($jsonarray));
  }

  //
  // Return MP list
  //
  private 
  function getmplist() {
    $query           = "select candidate from details";
    $result          = $this->dbconnection->execute($query);
    $jsonarray       = array();
    $i               = 0;
    while ( ($values = mysql_fetch_assoc($result)) ) {
      $jsonarray[$i] = $values['candidate'];
      $i++;
    } 
    printf("%s", json_encode($jsonarray));
  }

  private 
  function runquery($query) {
    error_log($query);
    $result          = $this->dbconnection->execute($query);
    $jsonarray       = array();
    $i               = 0;
    while ( ($values = mysql_fetch_assoc($result)) ) {
      $jsonarray[$i] = array(
        'name'         => $values['candidate'],
        'constituency' => $values['constituency'],
        'party'        => $values['party'],
        'cccount'      => $values['criminal_case_count'],
        'ccconvicted'  => $values['cases_details_convicted'],
        'ccaccused'    => $values['cases_details_accused'],
        'serious_ipc_detail' => $values['serious_ipc_detail'],
        'other_ipc_detail'   => $values['other_ipc_detail'],
        'education'          => $values['education'],
        'movable_assets'     => $values['movable_assets'],
        'immovable_assets'   => $values['immovable_assets'],
        'total_assets'       => $values['total_assets'],
        'liabilities'        => $values['liabilities'],
        'pan_given'          => $values['pan_given']
      );
      $i++;
    }
    printf("%s", json_encode($jsonarray));
  }
  //
  // Return politician details
  //
  private 
  function getdetails($name = "all") {
    if ( $name == "all" ) {
      $query         = "select * from details";
    }
    else {
      $query         = "select * from details where candidate = '" . $name ."'";
    }
    $result          = $this->dbconnection->execute($query);
    $jsonarray       = array();
    $i               = 0;
    while ( ($values = mysql_fetch_assoc($result)) ) {
      $jsonarray[$i] = array(
        'name'         => $values['candidate'],
        'constituency' => $values['constituency'],
        'party'        => $values['party'],
        'cccount'      => $values['criminal_case_count'],
        'ccconvicted'  => $values['cases_details_convicted'],
        'ccaccused'    => $values['cases_details_accused'],
        'serious_ipc_detail' => $values['serious_ipc_detail'],
        'other_ipc_detail'   => $values['other_ipc_detail'],
        'education'          => $values['education'],
        'movable_assets'     => $values['movable_assets'],
        'immovable_assets'   => $values['immovable_assets'],
        'total_assets'       => $values['total_assets'],
        'liabilities'        => $values['liabilities'],
        'pan_given'          => $values['pan_given']
      );
      $i++;
    }
    printf("%s", json_encode($jsonarray));
  }

  //
  // Load default/homepage.
  //
  private
  function loadpage() {
    $page = file_get_contents("inc/index.html");
    printf("%s", $page);
  }

  //
  // Main function
  //
  public
  function run() {
    if (isset($this->postargs[OPERATION])) {
      switch ($this->postargs[OPERATION]) {
        case GETMPLIST        : $this->getmplist(); break;
        case GETMPDETAILS     : $this->getdetails($this->postargs['mpname']); break;
        case GETALLDETAILS    : $this->getdetails(); break;
        case GRAPHSEARCH      : $this->graphsearch($this->postargs['string']); break;
        case RUNQUERY         : $this->runquery($this->postargs['query']); break;
      }
    }
    else
      $this->loadpage();
    return SUCCESS;
  }
}
?>
