import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;

/**
 * Created by legeek on 19/11/14.
 */
public class CarreMagique extends JFrame {
    private int size;
    private JPanel panels[][];
    private JTextField fields[][];
    private JLabel labels[][];


    CarreMagique( int size ){
        super( "Carre Magique" );
        setDefaultCloseOperation( EXIT_ON_CLOSE );
        setLayout( new GridLayout( size+1, size+2) );

        this.size = size;

        panels = new JPanel[size+1][size+2];
        labels = new JLabel[size+1][size+2];
        fields = new JTextField[size][size];

        for( int r = 0; r < size+1; ++r) {
            for (int c = 0; c < size + 2; ++c) {
                panels[r][c] = new JPanel();
                add( panels[r][c] );
            }
        }

        for( int r = 0; r < size+1; ++r ){
            labels[r][size+1] = new JLabel( "XxX" );
            panels[r][size+1].add(labels[r][size + 1]);
        }


        for( int c = 0; c < size+1; ++c ){
            labels[size][c] = new JLabel( "XxX" );
            panels[size][c].add( labels[size][c] );
        }

        for( int r = 0; r < size; ++r ) {
            for (int c = 0; c < size; ++c) {
                fields[r][c] = new JTextField( 3 );
                fields[r][c].addFocusListener(new FocusListener() {
                    @Override
                    public void focusGained(FocusEvent focusEvent) {}
                    @Override
                    public void focusLost(FocusEvent focusEvent) {
                        CarreMagique.this.updateLabelValue();
                    }
                });

                panels[r][c+1].add( fields[r][c]);
            }
        }

        pack();
        setVisible( true );
    }

    private void updateLabelValue(){
        for( int r = 0; r < size; ++r ){
            labels[r][size+1].setText(String.valueOf(sumLine(r)));
        }

        for( int c = 1; c < size+1; ++c){
            labels[size][c].setText(String.valueOf(sumCol(c-1)));
        }

        int sum = 0;
        for( int r = 0, c = 0; r < size; ++r, ++c)
            sum += Integer.valueOf(fields[r][c].getText().trim().equals("") ? "0" : fields[r][c].getText() );
        labels[size][size+1].setText( String.valueOf(sum) );

        sum = 0;
        for( int r = size-1, c = 0; r >= 0; --r, ++c)
            sum += Integer.valueOf(fields[r][c].getText().trim().equals("") ? "0" : fields[r][c].getText() );
        labels[size][0].setText( String.valueOf(sum) );
    }

    private int sumLine( int row ){
        int val = 0;

        for( int c = 0; c < size; ++c )
            val += Integer.valueOf(fields[row][c].getText().trim().equals("") ? "0" : fields[row][c].getText() );

        return val;
    }

    private int sumCol( int col ) {
        int val = 0;

        for (int r = 0; r < size; ++r)
            val += Integer.valueOf(fields[r][col].getText().trim().equals("") ? "0" : fields[r][col].getText() );

        return val;
    }
}
