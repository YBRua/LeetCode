from typing import List


# 2115-find-all-possible-recipes-from-given-supplies
class Solution:
    def findAllRecipes(
        self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]
    ) -> List[str]:
        supplies_set = set(supplies)
        recipe_to_ingredients = {
            recipe: ingredient for (recipe, ingredient) in zip(recipes, ingredients)
        }

        visited = {}  # -1: cannot make, 0: under processing, 1: can make
        result = []

        def _check_can_make(rcp: str):
            # visited[rcp] == 0 means we have a loop
            if rcp in visited and visited[rcp] == 0:
                return False

            if rcp in visited and visited[rcp] == 1:
                return True

            if rcp in supplies_set:
                visited[rcp] = 1
                return True

            if rcp not in recipe_to_ingredients:
                visited[rcp] = -1
                return False

            for ingred in recipe_to_ingredients[rcp]:
                if not _check_can_make(ingred):
                    visited[rcp] = -1
                    return False

            visited[rcp] = 1
            result.append(rcp)
            return True

        for rcp in recipes:
            _check_can_make(rcp)

        return result
