import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by legeek on 12/11/14.
 */
public class FentreLectureEntier extends JFrame {
    FentreLectureEntier(){
        super( "Curling !");
        setDefaultCloseOperation( EXIT_ON_CLOSE );
        setLayout( new FlowLayout() );

        JTextField textField = new JTextField( 2 );
        textField.addActionListener( new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                FentreLectureEntier.this.dispose();
                JOptionPane.showMessageDialog(null, "La gravité du tableau est de " + actionEvent.getActionCommand());
            }
        });

        add(new JLabel("gravité du tableau : "));
        add( textField );

        pack();
        setVisible( true );
    }

    public static void main(String[] args) {
        FentreLectureEntier fentreLectureEntier = new FentreLectureEntier();
    }
}
