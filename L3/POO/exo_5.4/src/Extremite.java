/**
 * Created by legeek on 22/10/14.
 */
public class Extremite {
    Composant composant;
    int num;

    Extremite(Composant c, int entree){
        composant=c;
        num=entree;
    }

    Extremite(Composant c){
        composant=c;
        num=0;
    }
}
