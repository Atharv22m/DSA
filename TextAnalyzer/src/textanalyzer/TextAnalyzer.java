/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package textanalyzer;
import java.util.Arrays;
import javax.swing.*;


/**
 *
 * @author athar
 */
public class TextAnalyzer {
    private String inputText;
    private Object[] uniqueCharString;
    private int length;
    private int words;
    private int spaces;
    private int lines;
    private int tabs;
    private ComboBoxModel model;
    
    TextAnalyzer(String inputText){
        this.inputText = inputText;
        performAnalysis();
        
    }
    
    public String getLength(){
        return Integer.toString(length);
    }
    
    public String getWords(){
        return Integer.toString(words);
    }
    
    public String getSpaces(){
        return Integer.toString(spaces);
    }
    
    public String getLines(){
        return Integer.toString(lines);
    }
    
    public String getTabs(){
        return Integer.toString(tabs);
    }
    
    public ComboBoxModel getModel(){
        return model;
    }
    
    public String getWordCount(String word){
        int count = 0;
        // Arrays.stream(s.split("")).distinct.toArray()
        String[] wordArray = inputText.split("[ .,\n\t]");
        for(String w: wordArray){
            if(word.equals(w)){
                count++;
            }
        }    
        return Integer.toString(count);
    }
    
    public String getCharCount(String character){
        int count = 0;
        for(int i = 0; i < inputText.length(); i++){
            if(character.charAt(0) == inputText.charAt(i)){
               count++;
            }
        }   
        return Integer.toString(count);
    }

    @Override
    public String toString() {
        return "TextAnalyzer{" + "length=" + length + ", words=" + words + ", spaces=" + spaces + ", lines=" + lines + ", tabs=" + tabs + '}';
    }
    
    private void performAnalysis(){
        length = inputText.length();

        words = inputText.split("[ \n\t]").length;
        
        spaces = inputText.split(" ", -1).length -1;
        
        lines = length>0?inputText.split("\n").length:0;
        
        tabs = inputText.split("\t", -1).length -1;
        
        /*
        for(int i = 0; i < inputText.length(); i++){
            if(inputText.charAt(i) == '\t'){
                tabs++;
            }
        }
        for(int i = 0; i < inputText.length(); i++){
            if(inputText.charAt(i) == '\n'){
                lines++;
            }
        }
        for(int i = 0; i < inputText.length(); i++){
            if(inputText.charAt(i) == ' '){
                spaces++;
            }
        }
        */
        uniqueCharString = Arrays.stream(inputText.split("")).sorted().skip(spaces+lines+tabs).distinct().toArray();
        model = new DefaultComboBoxModel<>(uniqueCharString);
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        TextAnalyzer t = new TextAnalyzer("fsgz jmjs");
        System.out.println(t);
    }
    
}
