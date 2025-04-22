/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sudokugame;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

/**
 *
 * @author athar
 */
public class SudokuGame {
    String[][] layout;
    String[][] userAns;
    int size;
    int remove;
    boolean valid;
    int[] rmvIndex;
    
    Integer[] getPN(){
        Integer[] pn = new Integer[size];
        for(int i = 0; i < size; i++){
            pn[i] = i + 1;
        }
        return pn;
    }

    List<Integer> checkColumn(List<Integer> list, int row, int col){
        for(int a = row; a >= 0; a--){
            for(int b = 0; b < list.size(); b++){
                if(Integer.parseInt(layout[a][col]) == list.get(b)){
                    list.remove(b);
                }
            }
        }
        return list;
    }

    void getLayout(){
        layout = new String[size][size];
	int trials = 0;
        
	for(int i=0; i<size; i++){
        if(trials < 30000){
            Integer[] pn = getPN();
            List<Integer> pnList = new ArrayList<>(Arrays.asList(pn));
            for(int j=0; j<size; j++){
                List<Integer> newList = new ArrayList<>(pnList);
                newList = checkColumn(newList, i-1, j);
                if(newList.size() == 0){
                    i = 0;
                    trials++;
                    break;
                }
                int r = (int) (Math.random() *10 % newList.size());
		layout[i][j] = newList.get(r).toString();
                pnList.remove(newList.remove(r));
            }
            }else{
            return;
        }
	}
        
    }
    
    void rmvElements() {
        Random random = new Random();
        rmvIndex = new int[2 * remove];
        int count = 0;
    
        while (count < remove) {
            int i = random.nextInt(size);
            int j = random.nextInt(size);
    
            if (!layout[i][j].equals(" ")) {
                layout[i][j] = " ";
                rmvIndex[2 * count] = i;
                rmvIndex[2 * count + 1] = j;
                count++;
            }
        }
    }
    
    int checkSolution(int row, int column){
        if(!userAns[row][column].matches("\\d+")){
            return 2;
        }
        else if(!(Integer.parseInt(userAns[row][column]) > 0) || !(Integer.parseInt(userAns[row][column]) < size+1)){
            return 2;
        }
        for(int checkcol = 0; checkcol < size; checkcol++){
            if(checkcol == column){
                continue;
            }
            else if(userAns[row][checkcol].equals(userAns[row][column])){
                return 0;
            }
        }
        for(int checkrow = 0; checkrow < size; checkrow++){
            if(checkrow == row){
                 continue;
            }
            else if(userAns[checkrow][column].equals(userAns[row][column])){
                return 0;
            }
        }
            
        
        return 1;
    }
    
       /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    }

    
}
