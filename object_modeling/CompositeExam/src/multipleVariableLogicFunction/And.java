package multipleVariableLogicFunction;

public class And extends BinaryOperand {
	
	private Satisfiable left ;
	private Satisfiable right;
	
	public void setLeftOperand (Satisfiable A) {
		this.left = A ;
	}
	
	public void setRightOperand (Satisfiable B) {
		this.right = B ;
	}
	
	public boolean isSatisfiable() {
		if(this.left.isSatisfiable() && this.right.isSatisfiable()) {
			return true;
		}
		else return false ;
	}
	
	public String toString() {
		return "(" + this.left.toString() + "." + this.right.toString() + ")";
	}
	
}
