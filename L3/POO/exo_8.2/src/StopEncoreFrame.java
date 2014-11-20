import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by legeek on 19/11/14.
 */
public class StopEncoreFrame extends JFrame {

    StopEncoreFrame(){
        super( "Stop / Encore" );
        setLayout( new FlowLayout() );
        setDefaultCloseOperation( EXIT_ON_CLOSE );

        JButton btnStop = new JButton( "STOP" );
        JButton btnEncore = new JButton( "ENCORE" );

        btnStop.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                StopEncoreFrame.this.dispose();
            }
        });

        btnEncore.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                new StopEncoreFrame();
            }
        });

        add( btnStop );
        add( btnEncore );

        pack();
        setVisible( true );
    }

    public static void main(String[] args) {
        new StopEncoreFrame();
    }
}
