Thank you for your interest in IEGEN project contribution! Please refer to the following sections on how to contribute code and bug reports.

# Reporting bugs
Before submitting a question or reporting a bug, please take a moment of your time and ensure that your issue isn't already discussed in the project documentation provided at [IEGEN documentation][https://iegen.picsart.com/master/] or in the [Github issue tracker](https://github.com/PicsArt/iegen/issues) . 
If you have identified a previously unknown problem, it's essential that you submit a self-contained and minimal piece of code that reproduces the problem. The bugs need to be reported in Gihub issue tracker, with “bug” label on them. In the Comment section, clearly explain what was your expectation, and what is the actual result of the execution. Try to isolate the function(s) that malfunction, attach the code snippets that can be easily compiled and run in isolation.
From the same issue tracker, You can also ask questions to IEGEN code owners, by using “question” label while creating the Issue.

# Pull requests
Contributions are submitted, reviewed, and accepted using GitHub pull requests. Please refer to [this article](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests) for details and adhere to the following rules to make the process as smooth as possible:
- Make a new branch for every feature you're working on.
- Make small and clean pull requests that are easy to review but make sure they do add value by themselves.
- While contributing, please, follow the Style Guide for Python Coding defined as [PEP 8](https://peps.python.org/pep-0008/).
- Add tests for any new functionality and run the test suite to ensure that no existing features break:
```
pytest ./src/test
```
- Also make sure to run end to end tests under examples/primitives with the following command:
```
bazel test //... --test_output=all
```
- Every pull request needs to have at least 2 approvals before being merged. The mandatory approvers are code owners of the repository.
- Merging is getting done by IEGEN code owners, who are in charge of the tool stability and maintainability.
 
# Release cycle
IEGEN releases will be created and published with bi-weekly cadence.
The release train will take all the merges done after the last release, and generate a new release tag for them, with Semantic Versioning rules. 
The new released package will be published <HERE, TBD>
Release Notes will be located in the Github Releases file, with the latest first order.

# Licensing of contributions
IEGEN is provided under a MIT license that can be found in the LICENSE file. By using, distributing, or contributing to this project, you agree to the terms and conditions of this license.
