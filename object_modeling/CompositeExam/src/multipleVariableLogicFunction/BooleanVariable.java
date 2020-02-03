package multipleVariableLogicFunction;

public class BooleanVariable extends Satisfiable {
	
	private String variable;
	private String label;
	private boolean correct ;
	
	public BooleanVariable(String string, String string2) {
		this.variable = string;
		this.label = string2;	
	}
	
	public void fixTruthValue(boolean b) {
		this.correct = b;
		
	}

	public String interpretation() {
		if (correct) {
			return this.label;
		}
		else {
			return "not " + this.label ;
		}
	}
	
	public boolean isSatisfiable() {
		return this.correct ;
	}
	
	
	public String toString() {
		return this.variable ;
	}

}
