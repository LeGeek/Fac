/**
 * Created by legeek on 08/10/14.
 */
public class FichierOrdinaire implements Fichier{
    private String filename;

    FichierOrdinaire( String filename ){
        this.filename = filename;
    }

    @Override
    public String getNom() {
        return filename;
    }
}
