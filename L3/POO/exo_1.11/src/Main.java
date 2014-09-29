/**
 * Created by legeek on 24/09/14.
 */
public class Main {
    public static void main(String[] args){
        System.out.println( "==== COMPTEUR SIMPLE ====" );
        CompteurSimple trimestre = new CompteurSimple(1, 4, "Trimestre");
        trimestre.affiche(); // affiche "Trimestre: 1"
        trimestre.inc(); trimestre.inc(); trimestre.inc();
        trimestre.affiche(); // affiche "Trimestre: 4"
        trimestre.inc();
        trimestre.affiche(); // affiche "Trimestre: 1"

        System.out.println( "\n==== COMPTEUR COMPOSE ====" );
        CompteurCompose c;
        c = new CompteurCompose(new CompteurSimple(0, 59, "Minute"),
                new CompteurCompose(new CompteurSimple(0, 23, "Heure"),
                        new CompteurCompose(new CompteurSimple(1, 365, "Jour"))));

        c.affiche(); // affiche "Jour: 1 Heure: 0 Minute: 0"
        for(int i = 1; i < 10000; i++)
            c.inc();

        c.affiche(); // affiche "Jour: 7 Heure: 22 Minute: 39"

        System.out.println("\n==== COPY & COMPARE ====");
        CompteurSimple cpTrimestre = new CompteurSimple( trimestre );
        System.out.println( "trimestre == cpTrimestre ? : " + trimestre.equals( cpTrimestre ) );

        CompteurCompose cpC = new CompteurCompose( c );
        System.out.println( "c == cpC ? : " + c.equals( cpC ) );
    }
}
