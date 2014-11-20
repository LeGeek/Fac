import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by legeek on 19/11/14.
 */
public class TaquinFrame extends JFrame {

    private JButton buttons[][];
    private int size;

    TaquinFrame( int size, int[][] values){
        super( "Taquin" );
        setDefaultCloseOperation( EXIT_ON_CLOSE );

        this.size = size;
        buttons = new JButton[size][size];
        JPanel panelBtn = new JPanel( new GridLayout(size, size) );
        JButton btn = new JButton( "Vérifier" );
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                if( verifier() )
                    JOptionPane.showMessageDialog(null, "Bravo !" );
                else
                    JOptionPane.showMessageDialog(null, "T'es nul !" );
            }
        });

        for(int i = 0; i < size; ++i ){
            for( int j = 0; j < size; ++j ){
                buttons[i][j] = new JButton( convertValue( values[i][j] ) );
                buttons[i][j].addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        searchEmptyCase( searchCase( ((JButton) actionEvent.getSource()) ) );
                    }
                });

                panelBtn.add( buttons[i][j] );
            }
        }

        add( panelBtn, BorderLayout.CENTER );
        add( btn, BorderLayout.SOUTH );

        pack();
        setVisible( true );
    }

    private String convertValue( int value ){
        if( value == 0)
            return "";
        else
            return String.valueOf( value );
    }

    private boolean verifier(){
        int tmp[] = new int[size*size];
        for(int i = 0; i < size; ++i )
            for( int j = 0; j < size; ++j)
                tmp[i*size+j] = Integer.valueOf( buttons[i][j].getText().equals( "" ) ? "0" : buttons[i][j].getText() );

        for( int i = 1; i < (size*size)-1; ++i )
            if( tmp[i-1] > tmp[i])
                return false;

        return true;
    }

    private void swapBtn( JButton a, JButton b){
        String c = a.getText();
        a.setText( b.getText() );
        b.setText( c );
    }

    private int[] searchCase( JButton value ){
        int[] ret = new int[2];

        for( int i = 0; i < size; ++i ) {
            for (int j = 0; j < size; ++j) {
                if (buttons[i][j] == value) {
                    ret[0] = i;
                    ret[1] = j;

                    return ret;
                }
            }
        }


        return null;
    }

    private void searchEmptyCase( int[] pos ){
        if( isEmptyCase( pos[0], pos[1]-1) ){
            swapBtn( buttons[pos[0]][pos[1]-1], buttons[pos[0]][pos[1]]);
        }
        else if( isEmptyCase( pos[0], pos[1]+1) ){
            swapBtn( buttons[pos[0]][pos[1]+1], buttons[pos[0]][pos[1]]);
        }
        else if( isEmptyCase( pos[0]-1, pos[1]) ){
            swapBtn( buttons[pos[0]-1][pos[1]], buttons[pos[0]][pos[1]]);
        }
        else if( isEmptyCase( pos[0]+1, pos[1]-1) ){
            swapBtn( buttons[pos[0]+1][pos[1]], buttons[pos[0]][pos[1]]);
        }
    }

    private boolean isEmptyCase( int i, int j){
        if( i < 0 || i >= size)
            return false;
        else if( j < 0 || j >= size )
            return false;

        if( buttons[i][j].getText().equals( "" ) )
            return true;
        else
            return false;
    }
}
