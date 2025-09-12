setup:
	@if ! command -v uv >/dev/null 2>&1; then \
	  curl -LsSf https://astral.sh/uv/install.sh | sh; \
	fi
	uv venv
	uv pip install -e .
	uv pip install -r requirements-dev.txt

test:
	uv run python -m unittest discover
