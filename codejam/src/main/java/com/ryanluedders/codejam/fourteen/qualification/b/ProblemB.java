package com.ryanluedders.codejam.fourteen.qualification.b;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.apache.commons.io.FileUtils;

import com.thoughtworks.xstream.XStream;

/**
 * Hello world!
 *
 */
public class ProblemB
{
	private static final XStream X = new XStream();

	private static final Double STARTING_RATE = 2.0;

	private static final String RESULT_FORMAT =
			"Case #%s: %.7f";

	private static class Problem {
		Integer numberCases;
		List<Case> cases = new ArrayList<Case>();
	};

	private static class Case {
		Double goal;
		Double cost;
		Double additional;
	}

	private static class Node {
		Node finishNode;
		Node farmNode;
		Double time;
	}

    public static void main( String[] args ) throws IOException
    {
		File inputFile = new File("./src/main/resources/b.in");
		List<String> data = FileUtils.readLines(inputFile,"UTF-8");

		File outputFile = new File("./src/main/resources/b.out");
		outputFile.delete();

		Problem problem = new Problem();
		problem.numberCases = Integer.valueOf(data.get(0));

		for(int i=0; i<problem.numberCases; i++) {
			problem.cases.add(readCase(data, i+1));
		}

		System.out.println(X.toXML(problem));

		int currentCase = 1;
		for (Case c : problem.cases) {

			Double currentRate = STARTING_RATE;

			Node rootNode = new Node();
			rootNode.time = 0.0;
			rootNode.finishNode = getFinishNode(rootNode, c, currentRate);
			rootNode.farmNode = getFarmNode(rootNode, c, currentRate);

			String resultString = String.format(
					RESULT_FORMAT,
					currentCase,
					getBestTime(rootNode)
					);

			if (currentCase != 1) {
				FileUtils.writeStringToFile(outputFile, "\n", true);
			}

			FileUtils.writeStringToFile(outputFile, resultString, true);
			System.out.println(resultString);

			currentCase += 1;
		}
    }

	private static Node getFinishNode(Node rootNode, Case cas, Double rate) {
		Node finishNode = new Node();
		finishNode.time = rootNode.time + (cas.goal / rate);
		finishNode.farmNode = null;
		finishNode.finishNode = null;
		return finishNode;
	}

	private static Node getFarmNode(Node rootNode, Case cas, Double rate) {
		Double previousTime = (rootNode == null) ? 0 : rootNode.time;

		Node thisNode = new Node();
		thisNode.time = previousTime + (cas.cost / rate);

		Double newRate = rate + cas.additional;
		thisNode.finishNode = getFinishNode(thisNode, cas, newRate);
		if (rootNode.finishNode.time > thisNode.finishNode.time) {
			thisNode.farmNode = getFarmNode(thisNode, cas, newRate);
		}
		return thisNode;
	}

	private static Double getBestTime(Node rootNode) {
		if (rootNode.farmNode == null ||
				rootNode.finishNode.time < rootNode.farmNode.finishNode.time)
		{
			return rootNode.finishNode.time;
		}
		else {
			return getBestTime(rootNode.farmNode);
		}
	}

    private static Case readCase(List<String> lines, int startIdx) {
    	Case thisCase = new Case();
    	List<String> values = Arrays.asList(lines.get(startIdx).split(" "));
    	thisCase.cost = Double.valueOf(values.get(0));
    	thisCase.additional = Double.valueOf(values.get(1));
    	thisCase.goal = Double.valueOf(values.get(2));
    	return thisCase;
    }
}
