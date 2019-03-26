/* This is a simple redirect script that redirects the user to the home page after 5 seconds.
 * This script is used on the HTTP Error Code pages.
 */

setTimeout(redirect, 5000);

function redirect(){
    //Redirect to index.php
    window.location.href = `../index.php`;
}