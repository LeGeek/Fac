/**
 * Created by legeek on 03/12/14.
 */
public class ToucheRepetee extends Touche {
    private int repetition;

    public ToucheRepetee( String nom, int repetition ){
        super( nom );
        this.repetition = repetition;
    }

    public int getRepetition(){
        return repetition;
    }
}
