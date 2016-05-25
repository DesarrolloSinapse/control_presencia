class Usuario < ActiveRecord::Base
	has_one :card
	has_many :logs

	validates :codigo, :nombre, :apellidos, :dni, :domicilio, :email, :dentro, :activo , presence: {message: ": Campo obligatorio"}
	validates :codigo, format: {with: /[0-9]{4}/, message: ": Formato incorrecto"}
	validates :dni, format: {with: /[0-9]{8}[A-Z]{1}/, message: ": Formato incorrecto"}
	validates :codigo, length: {is: 4, message: ": Longitud debe ser 4"}
	validates :dni, length: {is: 9, message: ": Longitud debe ser 9"}

	accepts_nested_attributes_for :card
end
