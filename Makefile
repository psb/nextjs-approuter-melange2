project_name = nextjs-approuter-melange2

DUNE = opam exec -- dune

.DEFAULT_GOAL := help

.PHONY: help
help: ## Print this help message
	@echo "List of available make commands";
	@echo "";
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}';
	@echo "";

.PHONY: create-switch
create-switch: ## Create opam switch
	opam switch create . 5.1.0 -y --deps-only

.PHONY: init
init: create-switch install ## Configure everything to develop this repository in local

.PHONY: install
install: ## Install development dependencies
	npm install # install JavaScript packages that the project might depend on, like `react` or `react-dom`
	opam update # make sure that opam has the latest information about published libraries in the opam repository https://opam.ocaml.org/packages/
	opam install -y . --deps-only --with-test # install the Melange and OCaml dependencies
	opam exec opam-check-npm-deps # check that the versions of the JavaScript packages installed match the requirements defined by Melange libraries

.PHONY: build
build: ## Build the project
	$(DUNE) build @nextjs

.PHONY: build_verbose
build_verbose: ## Build the project
	$(DUNE) build --verbose @nextjs

.PHONY: dev
dev: ## Serve the application with a local HTTP server
	cd _build/default/nextjs && npm run dev

.PHONY: bundle
bundle: ## Bundle the JS
	cd _build/default/nextjs && npm run build

.PHONY: preview
preview: ## Preview the built JS
	cd _build/default/nextjs && npm run start

.PHONY: lint
lint: ## JS lint
	cd _build/default/nextjs && npm run lint

.PHONY: clean
clean: ## Clean build artifacts and other generated files
	$(DUNE) clean

.PHONY: format
format: ## Format the codebase with ocamlformat
	$(DUNE) build @fmt --auto-promote

.PHONY: format-check
format-check: ## Checks if format is correct
	$(DUNE) build @fmt

.PHONY: watch
watch: ## Watch for the filesystem and rebuild on every change
	$(DUNE) build --watch @nextjs
