/* This is an experimental JS file created in an attempt to fix the fact that footer is hovering mid-screen when data boxes are open.
 * How this fix (hopefully) works is it will instantly hide the data reading boxes when the page loads.
 * Obviously the ideal thing to do would be to have the data reading boxes hidden from the very beginning.
 * But if doing it this way works then I'm keeping it. Although there is a good chance that this will just end up being unused.
 *
 * UPDATE: As expected, this file doesn't fix the issue and will probably be unused.
 * Will be keeping it here though in case it's needed for future use.
 */
 
var readBoxes; //Declare the variable, but leave blank for now.

function hB(){
    //Hide each reading box.
    for (i = 0; i < 5; i++){
        readBoxes = document.getElementById(`aquaUnitResults${i + 1}`);
        
        readBoxes.style.display = "none";
    }
}