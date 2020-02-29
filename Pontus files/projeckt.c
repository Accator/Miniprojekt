// 1: Koda spelet så det är funktionellt med knapparna.

// 2: Koda så spelet är funktionellt med acc och gyro.


//Spelarens storlek är 8x8
//Spelplanen 24 rader och 14 kolumner.


//Spelet kör i en virutuell spelplan
//Vi uppdaterar spelplanen hela tiden


//Function: Spelet
    //Function. Game interface tryck knapp för att starta.
        //Function: Får in data med info om rörelse som uppdaterar "spelarens pos" temporära position.
            //Function: som kollar om vi befinner oss innanför boxen i den virutella spelpalnen.
            //Function: IF utanför, börja blinka. Else, pass.
            //Function: Make temporära position, till current positon och uppdaterar spelplanen.
            //Function: som uppdaterar OLED
            
/*
Meny (när man inte är i ett spel)

Vill du starta spelet. Tryck på kanpp 1.
Vill du starta om spelet. Tryck på knapp 1.

*/

void menu (){

}

/*
Spelet.


Functionen kommer ligga i menu. 
Håll dig innanför ramen och du får poäng.
Är du utanför mer än 3 sekunder förlorar du.
Alla spel essentiella funktioner kommer ligg i denna


*/

void game (){
    
}

/*
Uppdatera spelplanen.

Hämtar data vart spelaren vill röra sig.
Subrutin som kollar om det är en krock, om inte.
Sätter positionen till 000.
Sätter tidigare position till 255.
Uppdaterar displayens input.
*/

void update (){

}






/*
Subrutin, krockhaterare.

Om den nya positionen inte 255 betyder det att vi har hamnat på en krock.
Här börjar den blinka som fan.
Fastnar i subrutinen till den lyckas ta sig till ett "leagal" position.
*/

void dangerZone (){
    
}







