/* This is a debug script for showing/hiding the confirm info button.
 * If the inTest variable is true, then the website will assume that testing is in progress and it will enable the button.
 * If it's false, then it will remove it.
 * For the record, the confirm info button can be found by hovering the mouse over the very top left corner of the index.php page.
 * However this shouldn't be accessible if the inTest variable is false.
 */

var inTest = false; //This variable can only be changed by editing the code!

function setAccess(){
    
    let dZ = document.getElementById(`debugZone`);
    
    console.log("Loaded!");

    if(inTest == true){
        dZ.style.display = "inline";
    }
    else if(inTest == false){
        dZ.parentNode.removeChild(dZ);
        
    }
    else{
        //If somehow the inTest variable isn't a boolean, the script will set it to true and re-run the function.
        alert("inTest variable wasn't a boolean. Setting to true.");
        
        inTest = true;
        
        setAccess();
    }
    
}