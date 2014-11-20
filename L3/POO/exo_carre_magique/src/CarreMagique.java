import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by legeek on 19/11/14.
 */
public class CarreMagique extends JFrame {
    private int size;
    private JTextField fields[][];

    CarreMagique( int size ){
        super( "Carre Magique" );
        setDefaultCloseOperation( EXIT_ON_CLOSE );
        setLayout( new GridLayout( size+1, size+2) );

        this.size = size;
        fields = new JTextField[size][size];
        for( int i = 0; i < size; ++i ){
            for( int j = 0; j < size; ++j ){
                fields[i][j] = new JTextField(5);
                fields[i][j].addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        updateLabelValue();
                    }
                });
                add( fields[i][j], i, j);
            }
        }

        for( int i = 0; i < size+1; ++i )
            //add( new JLabel( "XxX"), i, 0);

        pack();
        setVisible( true );
    }

    private void updateLabelValue(){

    }
}
