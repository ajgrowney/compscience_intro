function postValidation(){
  console.log(document.getElementById('post_content_text').value);
  if(document.getElementById('post_content_text').value == ""){
    alert("Must be non-empty post");
    return false;
  }else{
    return true;
  }

}
