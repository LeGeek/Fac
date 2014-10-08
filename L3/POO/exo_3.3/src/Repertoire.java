import java.util.ArrayList;
import java.util.List;

/**
 * Created by legeek on 08/10/14.
 */
public class Repertoire implements Fichier {
    private List<Fichier> files;
    private Repertoire parent;
    private String folderName;

    public Repertoire(){
        files = new ArrayList<Fichier>();
        folderName = "/";
        parent = this;
    }

    public Repertoire( String name, Repertoire parent){
        files = new ArrayList<Fichier>();
        folderName = name;
        this.parent = parent;
    }

    public void ajouter( Fichier file ){
        files.add( file );
    }

    public Fichier chercher( String filename ){
        if( filename.equals( ".." ) ){
            return parent;
        }

        for( int i = 0; i < files.size(); ++i ){
            if( files.get(i).getNom().equals( filename ) ){
                return files.get(i);
            }
        }

        return null;
    }

    public void affiche(){
        System.out.println( folderName + " : ");
        System.out.println( "\t.. -> " + parent.getNom());
        for( int i = 0; i < files.size(); ++i ){
            System.out.println( "\t" + files.get(i).getNom() );
        }
    }

    @Override
    public String getNom() {
        return folderName;
    }


    public static void main(String[] args) {
        Repertoire rep = new Repertoire();
        rep.ajouter( new FichierOrdinaire( "wvnjm" ) );
        rep.ajouter( new FichierOrdinaire( "!w" ) );
        rep.ajouter( new FichierOrdinaire( "dfdgt" ) );
        rep.ajouter( new FichierOrdinaire( "lgyvi" ) );
        rep.ajouter( new FichierOrdinaire( "sfvgbk" ) );
        rep.ajouter( new FichierOrdinaire( "k;" ) );
        rep.ajouter( new FichierOrdinaire( "qwerty" ) );
        rep.ajouter( new FichierOrdinaire( "wygrefgvbmjl" ) );
        rep.ajouter( new FichierOrdinaire( "!l:kjht" ) );
        rep.ajouter( new FichierOrdinaire( "nbgtdhey" ) );

        rep.affiche();

        System.out.print("Recherche de 'qwerty' : ");
        if( rep.chercher( "qwerty" ) != null){
            System.out.println( "TROUVE ! :)");
        }
        else{
            System.out.println( "NON TROUVE ! :(");
        }

        System.out.print("Recherche de 'azerty' : ");
        if( rep.chercher( "azerty" ) != null){
            System.out.println( "TROUVE ! :)");
        }
        else{
            System.out.println( "NON TROUVE ! :(");
        }
    }
}
