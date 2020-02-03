package multipleVariableLogicFunction;

public class Not extends UnaryOperand {
	
	private Satisfiable operand ;
	
	public void setOperande(Satisfiable A) {
		this.operand = A ;
		
	}
	
	public boolean isSatisfiable() {
		if(!this.operand.isSatisfiable()) {
			return true;
		}
		else return false ;
	}
	
	public String toString() {
		return "!" + this.operand.toString();
	}

}
