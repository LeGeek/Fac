import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by legeek on 19/11/14.
 */
public class TaquinBuildFrame extends JFrame{

    private JTextField textFields[][];
    private int size;

    TaquinBuildFrame( int size ){
        super("Taquin Builder");
        setDefaultCloseOperation( EXIT_ON_CLOSE );

        this.size = size;
        textFields = new JTextField[size][size];
        JPanel panelBtn = new JPanel( new GridLayout(size, size) );
        JButton btnOk = new JButton( "Ok" );
        btnOk.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                if( TaquinBuildFrame.this.checkGrid() ) {
                    TaquinBuildFrame.this.dispose();
                    new TaquinFrame( TaquinBuildFrame.this.size, generateArrayValue() );
                }
                else {
                    JOptionPane.showMessageDialog(null, "Grille invalide !!");
                }
            }
        });

        for( int i = 0; i < size; ++i ) {
            for (int j = 0; j < size; ++j) {
                textFields[i][j] = new JTextField();
                panelBtn.add(textFields[i][j]);
            }
        }

        add( panelBtn, BorderLayout.CENTER);
        add( btnOk, BorderLayout.SOUTH);

        pack();
        setVisible( true );
    }

    private boolean checkGrid(){

        boolean emptyCaseFound = false;
        for( int i = 0; i < size; ++i )
            for( int j = 0; j < size; ++j )
                if( textFields[i][j].getText().trim().equals( "" ) )
                    if( !emptyCaseFound )
                        emptyCaseFound = true;
                    else
                        return false;

        return emptyCaseFound;
    }

    private int[][] generateArrayValue(){
        int array[][] = new int[size][size];

        for( int i = 0; i < size; ++i)
            for( int j = 0; j < size; ++j)
                if( !textFields[i][j].getText().trim().equals( "" ))
                    array[i][j] = Integer.valueOf(textFields[i][j].getText());

        return array;
    }
}
