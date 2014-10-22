/**
 * Created by legeek on 22/10/14.
 */
public class BoiteAMeuhSaintValentin extends BoiteAMeuh {
    private static int nextNumeroSerie = 0;

    private int numeroSerie;
    private int nbAllerRetour;

    BoiteAMeuhSaintValentin(){
        nbAllerRetour = 0;
        numeroSerie = nextNumeroSerie;
        ++nextNumeroSerie;
    }

    int getNumeroSerie(){
        return numeroSerie;
    }

    void retourne(){
        if( nbAllerRetour >= 4 && !isUp ){
            System.out.print("Je t'ai");
            nbAllerRetour = 0;
        }

        super.retourne();

        if( isUp )
            ++nbAllerRetour;

    }

    public static void main(String[] args) {
        BoiteAMeuhSaintValentin b = new BoiteAMeuhSaintValentin();

        for( int i = 0; i < 12; ++i)
            b.retourne();
    }
}
