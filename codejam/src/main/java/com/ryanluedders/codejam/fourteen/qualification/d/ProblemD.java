package com.ryanluedders.codejam.fourteen.qualification.d;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.apache.commons.io.FileUtils;

import com.thoughtworks.xstream.XStream;

public class ProblemD
{
	private static final XStream X = new XStream();

	private static final String RESULT_FORMAT =
			"Case #%s:\n%s";

	private static final String RESULT_IMPOSSIBLE = "Impossible";

	private static class Problem {
		Integer numberCases;
		List<Case> cases = new ArrayList<Case>();
	};

	private static class Case {
		Integer numBlocks;
		List<Double> kenBlocks = new ArrayList<Double>();
		List<Double> naomiBlocks = new ArrayList<Double>();
	}

    public static void main( String[] args ) throws IOException
    {
		File inputFile = new File("./src/main/resources/d.in");
		List<String> data = FileUtils.readLines(inputFile,"UTF-8");

		File outputFile = new File("./src/main/resources/d.out");
		outputFile.delete();

		Problem problem = new Problem();
		problem.numberCases = Integer.valueOf(data.get(0));

		for(int i=0; i<problem.numberCases; i++) {
			problem.cases.add(readCase(data, (3*i)+1));
		}

		System.out.println(X.toXML(problem.cases));

		int currentCase = 1;
		for (Case c : problem.cases) {

			String resultString = String.format(
					RESULT_FORMAT,
					currentCase,
					""
					);

			if (currentCase != 1) {
				FileUtils.writeStringToFile(outputFile, "\n", true);
			}

			FileUtils.writeStringToFile(outputFile, resultString, true);
			System.out.println(resultString);

			currentCase += 1;
		}
    }

    private static Case readCase(List<String> lines, int startIdx) {
    	Case thisCase = new Case();
    	thisCase.numBlocks = Integer.valueOf(lines.get(startIdx++));
    	for (String block : Arrays.asList(lines.get(startIdx++).split(" "))) {
    		thisCase.naomiBlocks.add(Double.valueOf(block));
    	}
    	for (String block : Arrays.asList(lines.get(startIdx++).split(" "))) {
    		thisCase.kenBlocks.add(Double.valueOf(block));
    	}
    	return thisCase;
    }
}
