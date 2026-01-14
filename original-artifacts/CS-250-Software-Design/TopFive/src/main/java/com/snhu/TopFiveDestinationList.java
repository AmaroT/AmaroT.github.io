package com.snhu;

import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;

public class TopFiveDestinationList {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                TopDestinationListFrame topDestinationListFrame = new TopDestinationListFrame();
                topDestinationListFrame.setTitle("Top 5 Destination List");
                topDestinationListFrame.setVisible(true);
            }
        });
    }
}
class TopDestinationListFrame extends JFrame {
    private DefaultListModel<TextAndIcon> listModel;

    public TopDestinationListFrame() {
        super("Top Five Destination List");

        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setSize(900, 750);

        // Add developer name at the top
        JLabel nameLabel = new JLabel("Created by Amaro Terrazas", SwingConstants.CENTER);
        nameLabel.setFont(new Font("SansSerif", Font.BOLD, 14));
        getContentPane().add(nameLabel, BorderLayout.NORTH);

        // Initialize the list model
        listModel = new DefaultListModel<>();

        // Add destinations
        addDestinationNameAndPicture("1. Tokyo, Japan - A vibrant metropolis blending traditional temples with futuristic skyscrapers.", new ImageIcon(getClass().getResource("/tokyo.jpg")), "Benh LIEU SONG");
        addDestinationNameAndPicture("2. Paris, France - The City of Light, known for its iconic landmarks, art, and cuisine.", new ImageIcon(getClass().getResource("/paris.jpeg")),"Wladyslaw");
        addDestinationNameAndPicture("3. Sydney, Australia - A harbor city famed for its Opera House, beaches, and laid-back lifestyle.", new ImageIcon(getClass().getResource("/sydney.jpg")), "Diliff");
        addDestinationNameAndPicture("4. Rome, Italy - The Eternal City, famous for its ancient ruins, art, and culinary delights.", new ImageIcon(getClass().getResource("/rome.jpg")), "Diliff");
        addDestinationNameAndPicture("5. New York City, USA - The city that never sleeps, offering world-class museums, theaters, and skyline views.", new ImageIcon(getClass().getResource("/nyc.jpg")),"Dllu");

        // Create a JList with the list model
        JList<TextAndIcon> list = new JList<>(listModel);
        list.setBackground(new Color(245, 245, 245)); // Light Gray Background
        list.setFont(new Font("Verdana", Font.PLAIN, 12)); // Font update
        list.setForeground(Color.DARK_GRAY); // Text Color
        JScrollPane scrollPane = new JScrollPane(list);

        // Set custom renderer
        TextAndIconListCellRenderer renderer = new TextAndIconListCellRenderer(10);
        list.setCellRenderer(renderer);

        getContentPane().add(scrollPane, BorderLayout.CENTER);
    }

    private void addDestinationNameAndPicture(String text, Icon icon, String credit) {
        // Include the credit in the text to display it below the image
        String fullText = "<html>" + text + "<br><i>Credit: " + credit + "</i></html>";
        TextAndIcon tai = new TextAndIcon(fullText, icon);
        listModel.addElement(tai);
    }
}


class TextAndIcon {
    private String text;
    private Icon icon;

    public TextAndIcon(String text, Icon icon) {
        this.text = text;
        this.icon = icon;
    }

    public String getText() {
        return text;
    }

    public Icon getIcon() {
        return icon;
    }

    public void setText(String text) {
        this.text = text;
    }

    public void setIcon(Icon icon) {
        this.icon = icon;
    }
}


class TextAndIconListCellRenderer extends JLabel implements ListCellRenderer {
    private static final Border NO_FOCUS_BORDER = new EmptyBorder(1, 1, 1, 1);

    private Border insideBorder;

    public TextAndIconListCellRenderer() {
        this(10, 10, 10, 10); // Add padding
    }

    public TextAndIconListCellRenderer(int padding) {
        this(padding, padding, padding, padding);
    }

    public TextAndIconListCellRenderer(int topPadding, int rightPadding, int bottomPadding, int leftPadding) {
        insideBorder = BorderFactory.createEmptyBorder(topPadding, leftPadding, bottomPadding, rightPadding);
        setOpaque(true);
    }

    public Component getListCellRendererComponent(JList list, Object value,
                                                  int index, boolean isSelected, boolean hasFocus) {
        // The object from the combo box model MUST be a TextAndIcon.
        TextAndIcon tai = (TextAndIcon) value;


        // Sets text and icon on 'this' JLabel.
        setText(tai.getText());
        setIcon(tai.getIcon());

        if (isSelected) {
            setBackground(list.getSelectionBackground());
            setForeground(list.getSelectionForeground());
        } else {
            setBackground(list.getBackground());
            setForeground(list.getForeground());
        }

        Border outsideBorder;

        if (hasFocus) {
            outsideBorder = UIManager.getBorder("List.focusCellHighlightBorder");
        } else {
            outsideBorder = NO_FOCUS_BORDER;
        }

        setBorder(BorderFactory.createCompoundBorder(outsideBorder, insideBorder));
        setComponentOrientation(list.getComponentOrientation());
        setEnabled(list.isEnabled());
        setFont(list.getFont());

        return this;
    }

    // The following methods are overridden to be empty for performance
    // reasons. If you want to understand better why, please read:
    //
    // http://java.sun.com/javase/6/docs/api/javax/swing/DefaultListCellRenderer.html#override

    public void validate() {}
    public void invalidate() {}
    public void repaint() {}
    public void revalidate() {}
    public void repaint(long tm, int x, int y, int width, int height) {}
    public void repaint(Rectangle r) {}
}
