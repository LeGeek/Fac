/**
 * Created by legeek on 08/10/14.
 */
public class Systeme {
    Repertoire workDir;

    public Systeme(){
        workDir = new Repertoire();
        mkdir( "home" );
        mkdir( "bin" );
    }

    public Repertoire mkdir( String nom ){
        Repertoire rep = new Repertoire( nom, workDir);
        workDir.ajouter( rep );

        return rep;
    }


    public void cd( String rep ){
        if( rep == ".."){
            workDir = (Repertoire) workDir.chercher( ".." );
        }
        else if( rep == "/" ){
            while( workDir.getNom() != "/"){
                workDir = (Repertoire) workDir.chercher( ".." );
            }
        }
        else{
            Fichier tmp = workDir.chercher( rep );
            if( tmp != null && tmp instanceof Repertoire){
                workDir = (Repertoire)tmp;
            }
        }
    }

    public void ls(){
        workDir.affiche();
    }

    public void ls( String nom ){
        Fichier tmp = workDir.chercher( nom );

        if( tmp instanceof Repertoire ){
            ((Repertoire)tmp).affiche();
        }
        else{
            tmp.getNom();
        }
    }

    public void creeCompte( String login ){
        Repertoire oldWorkDir = workDir;

        cd( "/" );
        cd( "home" );
        mkdir( login );
        cd( login );
        workDir.ajouter( new FichierOrdinaire( ".bashrc" ) );

        workDir = oldWorkDir;
    }

    public void login( String login ){
        cd( "/" );
        cd( "home" );
        cd( login );
    }

    public static void main(String[] args) {
        Systeme s = new Systeme();
        s.creeCompte("moi");
        s.creeCompte("pasmoi");
        s.login("moi");
        s.ls(); // affiche ".bashrc"
        s.ls(".."); // affiche "moi" et "pasmoi"
        s.cd("..");
        s.mkdir("rep");
        s.ls(); // affiche "moi", "pasmoi" et "rep"
        s.ls("moi"); // affiche ".bashrc"
        s.ls(".."); // affiche "home" et "bin"
    }
}
