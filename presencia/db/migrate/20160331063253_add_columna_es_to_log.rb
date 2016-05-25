class AddColumnaEsToLog < ActiveRecord::Migration
  def change
  	add_column :logs, :entrada, :boolean
  end
end
