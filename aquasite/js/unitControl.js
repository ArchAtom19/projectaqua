//This first variable signifies whether each unit reading box is expanded or not. True = Expanded.
var expanded = [false, false, false, false, false];

function unitToggle(unit){
    
    let buttonAlter = document.getElementById(`toggleButton${unit}`);
    let resultShow = document.getElementById(`aquaUnitResults${unit}`);
    
    if(expanded[unit - 1] == false){
        
       /* Set te corresponding value in the expanded array to true.
        * Then swap the graphics for the button and reveal the results table.
        */
        expanded[unit - 1] = true;
        
        buttonAlter.src = `../img/aquaButtonShrink.png`;
        resultShow.style.display = "flex";
    }
    else{
        //Pretty much the reverse of the above.
        expanded[unit - 1] = false;
        
        buttonAlter.src = `../img/aquaButtonExpand.png`;
        resultShow.style.display = "none";
    }
    
}