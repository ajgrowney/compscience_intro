//Check if the user id is empty
  function required(){
    if(document.getElementById("newuser_id").value == ""){
        alert("Must provide a user id non empty");
        return false;
    }else{
      return true;
    }
  }
