package multipleVariableLogicFunction;

public class LogicalExpressionWith4Variables {

	private TableOfSymbols symbols;
	
	public Satisfiable constructLogicalEpressionWith4Variables() {
		this.symbols = new TableOfSymbols();
		BooleanVariable a = new BooleanVariable("a", "Enough money");
		this.symbols.addVariable(a);
		BooleanVariable b = new BooleanVariable("b", "Homework done");
		this.symbols.addVariable(b);
		BooleanVariable c = new BooleanVariable("c", "Public transport is on strike");
		this.symbols.addVariable(c);
		BooleanVariable d = new BooleanVariable("d", "Family automobile is available");
		this.symbols.addVariable(d);
		BinaryOperand leftConjunction = new And();
		leftConjunction.setLeftOperand(a);
		leftConjunction.setRightOperand(b);
		
		
		UnaryOperand notC = new Not();
		notC.setOperande(c);
		BinaryOperand rightConjunction = new Or();
		rightConjunction.setLeftOperand(notC);
		rightConjunction.setRightOperand(d);
		
		BinaryOperand goOut = new And();
		goOut.setLeftOperand(leftConjunction);
		goOut.setRightOperand(rightConjunction);
		return goOut;
	}
	public void whenGoOut(Satisfiable goOut) {
		for (int i = 0; i <= Math.pow(2,4) -1; i++) {
			this.symbols. fixTruthValue (i,4);
			if (goOut.isSatisfiable()) {
				System.out.print("I go out one evening when: ");
				for (int j = 0; j < 4; j++) {
					System.out.print(this.symbols.interpretation(j));
					if (j < 3)
						System.out.print(" and ");
				}
				System.out.println();
			}
		}
	}

	public void whenNotGoOut (Satisfiable goOut) {
		for (int i = 0; i <= Math.pow(2,4) -1; i++) {
			this.symbols. fixTruthValue (i,4);
			if (!goOut.isSatisfiable()) {
				System.out.print("I don't dont go out one evening when: ");
				for (int j = 0; j < 4; j++) {
					System.out.print(this.symbols.interpretation(j));
					if (j < 3)
						System.out.print(" and ");
				}
				System.out.println();
			}
		}
	}
	public static void main(String[] args) {
		LogicalExpressionWith4Variables customer = new LogicalExpressionWith4Variables();
		Satisfiable goOut = customer.constructLogicalEpressionWith4Variables();
		System.out.print("Evaluation of Boolean expression: ");
		System.out.println(goOut);
		for (int i = 0; i <= Math.pow(2,4) -1; i++) {
			customer.symbols. fixTruthValue (i,4);
			System.out.println(goOut.isSatisfiable());
		}
		customer.whenGoOut(goOut);
		customer.whenNotGoOut(goOut);
	}
}
