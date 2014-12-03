import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by legeek on 19/11/14.
 */
public class Main extends JFrame {
    Main(){
        super( "Taille du carre magique" );
        setDefaultCloseOperation( EXIT_ON_CLOSE );
        setLayout( new FlowLayout() );

        TextField textField = new TextField(2);
        textField.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                int size = Integer.valueOf( actionEvent.getActionCommand() );
                if( size % 2 == 0){
                    JOptionPane.showMessageDialog( null, "Le nombre doit être impaire !" );
                    return;
                }

                Main.this.dispose();
                new CarreMagique( size );
            }
        });

        add(new Label("Entrez la taille du Taquin : "));
        add( textField );

        pack();
        setVisible( true );
    }

    public static void main(String[] args) {
        new Main();
    }
}
