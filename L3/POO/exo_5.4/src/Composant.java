import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * Created by legeek on 22/10/14.
 */
public abstract class Composant {
    int valeur;
    List<Extremite> sorties;
    Composant entrees[];

    Composant(){
        valeur = -1;
        sorties = new ArrayList<Extremite>();
        entrees = new Composant[2];
    }

    abstract void miseAJour();

    void raccorde( Extremite comp ){
        sorties.add(comp);
        comp.composant.entrees[ comp.num ] = this;

        System.out.println("Raccord de " + this + " avec " + comp.composant + " sur l'entrée " + comp.num);

        miseAJour();
    }

    void propager()
    {
        for( Iterator it = sorties.iterator(); it.hasNext(); )
            ( (Extremite) it.next()).composant.miseAJour();
    }

}
