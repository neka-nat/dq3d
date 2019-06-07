setup:
	pip install pipenv
	pipenv run pip install pip==18.0
	pipenv install --dev
	pipenv run pip install -e .
