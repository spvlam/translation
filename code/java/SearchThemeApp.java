import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class SearchThemeApp extends JFrame {
    private JTextField searchField;
    private JTextArea resultArea;
    public SearchThemeApp() {
        setTitle("Search Theme App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        // Create the search field
        searchField = new JTextField();
        searchField.setPreferredSize(new Dimension(300, 30));
        searchField.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {
                // Perform search as you type
                performSearch(searchField.getText());
            }
            @Override
            public void keyPressed(KeyEvent e) {
            }

            @Override
            public void keyReleased(KeyEvent e) {
            }
        });

        // Create the result area
        resultArea = new JTextArea();
        resultArea.setEditable(false);

        // Add components to the frame
        add(searchField, BorderLayout.NORTH);
        add(new JScrollPane(resultArea), BorderLayout.CENTER);

        pack();
        setLocationRelativeTo(null);
    }

    private void performSearch(String searchTerm) {
        // Perform the search based on the given search term
        // Replace this with your own search logic
        // For demonstration purposes, let's simply display the search term in the result area
        resultArea.setText("Searching for: " + searchTerm);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            SearchThemeApp app = new SearchThemeApp();
            app.setVisible(true);
        });
    }   
}
