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
        buttonAlter.alt = `Shrink`;
        resultShow.style.display = "block";
        setFooterBottom();
    }
    else{
        //Pretty much the reverse of the above.
        expanded[unit - 1] = false;
        
        buttonAlter.src = `../img/aquaButtonExpand.png`;
        buttonAlter.alt = `Expand`;
        resultShow.style.display = "none";
        setFooterBottom();
    }
    
}

function setFooterBottom(){
    let footerDown = document.getElementsByTagName(`FOOTER`)[0]; //Assumes that there is only one footer in the entire web page.
    
    footerDown.style.position = "absolute";
    footerDown.style.bottom = 0;
}