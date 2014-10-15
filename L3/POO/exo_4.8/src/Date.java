/**
 * Created by legeek on 15/10/14.
 */
public class Date {
    private static Date maintenant;
    private int date;

    Date( int date ){
        this.date = date;
    }

    Date plus( int add ){
        return new Date( date + add );
    }

    boolean avant( Date d ){
        return d.getDate() > date;
    }

    public static Date getMaintenant() {
        return maintenant;
    }

    public static void setMaintenant( Date maintenant ) {
        Date.maintenant = maintenant;
    }

    int getDate(){
        return date;
    }
}
