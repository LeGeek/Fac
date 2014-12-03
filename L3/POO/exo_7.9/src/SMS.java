/**
 * Created by legeek on 03/12/14.
 */
public interface SMS {
    void ajouter( char c );
    void supprimerPrecedent();
    char dernier();
    void terminer();
    String message();
}
