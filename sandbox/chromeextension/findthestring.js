
var elements = [];
var words    = [];

//
// Make AJAX Request
//
function ajaxrequest(requrl, reqdata, successcallback) {
  $.ajax({
    url        : requrl,
    data       : reqdata,
    type       : 'POST',
    dataType   : 'json',
    crossDomain: true,
    success    : function(data) {
      successcallback(data);
    },
    error      : function(error) {
      console.log("ERROR");
    }
  });
}

function displaydetails(data) {
  console.log("displaydetails");
  console.log(data);
}

function updatewords(data) {

  console.log("updatewords");
  words = data;
  $.each(words, function(index, word) {
    var queue = [document.body];
    var curr;
    while (curr = queue.pop()) {
      if (!curr.textContent.toLowerCase().match(word)) continue;
      for (var i = 0; i < curr.childNodes.length; ++i) {
        switch (curr.childNodes[i].nodeType) {
          case Node.TEXT_NODE :  if (curr.childNodes[i].textContent.toLowerCase().match(word)) {
            elements.push(curr);
          }
          break;

          case Node.ELEMENT_NODE :  queue.push(curr.childNodes[i]);
            break;
        }
      }
    }
    spanaround(word);
    elements = [];
  })
}

function spanaround(word) {
  $.each(elements, function(index, element) {;
    var stringsarray = $(element).html().toString();
    var htmlstring = stringsarray.replace(new RegExp(word, "gi"), ("<span class='netagyan' style='text-transform:capitalize;'>" + word + "</span>"));
    $(element).empty().html(htmlstring);
  })
  $.each($("span.netagyan"), function() {
    var popup = $("<div>", {"id": "netagyanpopup"}).css("position", "absolute").css("z-index", "9999").css("top", "0");
    $(this).unbind().bind("click", function() {
      console.log(this.textContent);
      var reqdata = {
        "operation":'getmpdetails',
        "mpname"   : this.textContent
      };
      ajaxrequest("http://localhost/index.php", reqdata, displaydetails);
    });
    $(this).bind("mouseout", function() {
      $(popup).empty().remove();
    });
  });
};

window.onload = function() {
  var reqdata = {"operation":'getmplist'};
  ajaxrequest("http://localhost/index.php", reqdata, updatewords);
}
