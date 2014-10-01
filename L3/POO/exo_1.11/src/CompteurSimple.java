/**
 * Created by legeek on 24/09/14.
 */
public class CompteurSimple {
    private int value;
    private int minValue;
    private int maxValue;
    private String nom;

    public CompteurSimple( int v, int max, String libelle ){
        value = v;
        minValue = v;
        maxValue = max;
        nom = libelle;
    }

    public CompteurSimple( CompteurSimple cpt ){
        minValue = cpt.getMinValue();
        maxValue = cpt.getMaxValue();
        value = cpt.getValue();
        nom = new String( cpt.getNom() );
    }

    public boolean inc(){
        if( (++value) > maxValue ) {
            value = minValue;
            return true;
        }

        return false;
    }

    public void affiche(){
        System.out.println( nom + " : " + value);
    }

    public String getNom() {
        return nom;
    }

    public int getValue() {
        return value;
    }

    public int getMinValue() {
        return minValue;
    }

    public int getMaxValue() {
        return maxValue;
    }

    public boolean equals( CompteurSimple toCompare ){
        return  nom.equals( toCompare.getNom() ) &&
                value == toCompare.getValue() &&
                minValue == toCompare.getMinValue() &&
                maxValue == toCompare.getMaxValue();
    }
}
